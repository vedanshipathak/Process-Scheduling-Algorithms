#include<bits/stdc++.h>
using namespace std;
struct Process
{
  public:
  int pid;//process id
  int at;//arrival time
  int bt;//burst time
  int tat;//turn around time
  int ct;//completion time
  int wt;//wait time
};
int main()
{
  int n;
  cout<<"Enter the number of process:"<<endl;
  cin>>n;
  vector<Process>p(n);
  //intput values for at and bt for every process
  cout<<"Enter the Arrival time:";
  for(int i=0;i<n;i++)
  {
    p[i].pid=i+1;
    cout<<p[i].pid<<":\t";
    cin>>p[i].at;
    cout<<endl;
  }
  cout<<"Enter the Burst time:";
  for(int i=0;i<n;i++)
  {
    p[i].pid=i+1;
    cout<<p[i].pid<<":\t";
    cin>>p[i].bt;
    cout<<endl;
  }
  //calculate the completion time
  //the one with at=0 will be executed first
  sort(p.begin(), p.end(), [](const Process& a, const Process& b) {
        return a.at < b.at;
    });
  p[0].ct=p[0].bt;
  for(int i=1;i<n;i++)
  {
     p[i].ct=p[i-1].ct+p[i].bt;
  }
  //calculate the turn around time
  for(int i=0;i<n;i++)
  {
    p[i].tat=p[i].ct-p[i].at;
  }
  //calculate the wait time
  for(int i=0;i<n;i++)
  {
    p[i].wt=p[i].tat-p[i].bt;
  }
  //display every thing
  cout<<"PID"<<"\t\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT\t"<<"TAT\t"<<"WT"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<endl;
  }
  //average time
  double sum=0;
  for(int i=0;i<n;i++)
  {
    sum=sum+p[i].wt;
  }
  double avg=sum/n;
  cout<<"AVERAGE WAIT TIME:"<<avg<<endl;

}
