#include <iostream>
using namespace std;

class o2
{
  private:
    int lev,x;
    int n;
    float m[12][12]={{0,20.2,5.5,14.8,4.5,6.1,15.2,4.8,6.6,9.6,8.4,15},
    {20.2,0,14.8,10.7,20.4,14.8,17.5,20.7,15.4,7.6,11.8,9.2},
    {5.5,14.8,0,11.1,7.6,7.1,14.4,5.5,7.7,5,5.1,16.9},
    {14.8,10.7,11.1,0,16,11,18.7,10.6,11.5,6,10.2,14.4},
    {4.5,20.4,7.6,16,0,6.5,10.9,11.1,7.1,11.8,11.7,15.4},
    {6.1,14.8,7.1,11,6.5,0,9.1,10.1,1.5,6.9,10.7,10},
    {15.2,17.5,14.4,18.7,10.9,9.1,0,18.6,7.6,14.8,18.2,12.5},
    {4.8,20.7,5.5,10.6,11.1,10.1,18.6,0,11.6,6.3,2.4,18.2},
    {6.6,15.4,7.7,11.5,7.1,1.5,7.6,11.6,0,6.4,10.2,9.6},
    {9.6,7.6,5,6,11.8,6.9,14.8,6.3,6.4,0,6.9,12.4},
    {8.4,11.8,5.1,10.2,11.7,10.7,18.2,2.4,10.2,6.9,0,18.9},
    {15,9.2,16.9,14.4,15.4,10,12.5,18.2,9.6,12.4,18.9,0}};


  public:
    void info();
    int getInfo();
    void showInfo();
    void cal(int);
    int voc();
};

int o2::voc()
{
    cin>>x;
    return x;
}

int o2::getInfo()
{
    cin>>lev;
  if(lev==1||lev==2||lev==3)
  {
      return lev;
  }
  else{cout<<"wrong input"<<endl;}
}

void o2::info()
{
  cout<<"1.Apollo Hospitals";
  cout<<endl;
  cout<<"2.Dr. Kamakshi Memorial Hospital";
  cout<<endl;
  cout<<"3.Dr. Mehta's Hospital";
  cout<<endl;
  cout<<"4.Fortis Malar Hospital";
  cout<<endl;
  cout<<"5.Frontier Lifeline Hospital";
  cout<<endl;
  cout<<"6.SIMS Hospital";
  cout<<endl;
  cout<<"7.Sri Ramachandra Medical Centre";
  cout<<endl;
  cout<<"8.The Madras Medical Mission";
  cout<<endl;
  cout<<"9.Vijaya Group of Hospitals";
  cout<<endl;
  cout<<"10.Cloudnine Hospital";
  cout<<endl;
  cout<<"11.Rajiv Gandhi Government General Hospital";
  cout<<endl;
  cout<<"12.Mount Multispeciality Hospitals";
  cout<<endl<<endl;

  int i,j;
  for(i=0;i<12;i++)
  {
    for(j=0;j<12;j++)
    {
      cout<<"\t";
      cout<<m[i][j];
    }
    cout<<endl;
  }
  cout<<"Critical stage 1 for more than 6 cylinders."<<endl;
  cout<<"Critical stage 2 for between 3 and 6 cylinders."<<endl;
  cout<<"Critical stage 3 for less then 3 cylinders."<<endl;
  cout<<"If the hospital is in village enter 1"<<endl;
  cout<<"If the hospital is in city enter 2"<<endl;
  cout<<"Enter the critical stage and if the hosptal is in village or in city for:"<<endl;
}

int main()
{
  o2 o;
  o.info();
  int i;
  int a[12],b[12];
  char hos[12][50]={"1.Apollo Hospitals","2.Dr. Kamakshi Memorial Hospital","3.Dr. Mehta's Hospital","4.Fortis Malar Hospital","5.Frontier Lifeline Hospital",
"6.SIMS Hospital","7.Sri Ramachandra Medical Centre","8.The Madras Medical Mission","9.Vijaya Group of Hospitals","10.Cloudnine Hospital","11.Rajiv Gandhi Government General Hospital",
"12.Mount Multispeciality Hospitals"};
  for(i=0;i<12;i++)
  {
    cout<<hos[i]<<"\t";
    a[i]=o.getInfo();
    cout<<"\t\t\t";
    b[i]=o.voc();
  }

  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==3 && b[i]==1)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==3 && b[i]==2)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==2 && b[i]==1)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==2 && b[i]==2)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==1 && b[i]==1)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  for(i=0;i<12;i++)
  {
      int j=0;
      j=i+1;
    if(a[i]==1 && b[i]==2)
    {
        cout<<"Hospital no."<<j<<endl;

    }
  }
  return 0;
}
 
