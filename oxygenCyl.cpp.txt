#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;
float a[12][12]={{0,20.2,5.5,14.8,4.5,6.1,15.2,4.8,6.6,9.6,8.4,15},
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
char hospitals[11][50] = {"Dr. Kamakshi Memorial Hospital", "Dr. Mehta's Hospital",
"Fortis Malar Hospital","Frontier Lifeline Hospital","SIMS Hospital","Sri Ramachandra Medical Centre",
"The Madras Medical Mission",
"Vijaya Group of Hospitals",
"Cloudnine Hospital",
"Rajiv Gandhi Government General Hospital","Mount Multispeciality Hospitals"};
int visited[20],n;
float cost=0;
int priority[20];

void get()
{
	int i,j;
	cout<<"Enter total no. of points(including the starting point): ";
	cin>>n;
	for(i=0;i < n;i++)
	{
		visited[i]=0;
	}
	cout<<"\n\nThe distance matrix is:\n\n";
	for( i=0;i < n;i++)
	{
		cout<<"\n\n";
		for(j=0;j < n;j++)
			cout<<"\t"<<a[i][j];
	}
}

float least(int c)
{
	float nc=999;
	float min=999,kmin;
	for(int i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(visited[i]==0))
			if(a[c][i] < min)
			{
				min=a[c][i];
				kmin=a[c][i];
				nc=i;
			}
	}
	if(min!=999)
		cost+=kmin;
	return nc;
}

void mincost(int point)
{
	int i,npoint;
	visited[point]=1;
	cout<<point+1<<" -->";
	npoint=least(point);
	if(npoint==999)
	{
		npoint=0;
		cout<<npoint+1;
		cost+=a[point][npoint];
		return;
	}
	mincost(npoint);
}
int level()
{   int temp;
    cout<<"\n\nEnter oxygen level";
    cout<<"\n\nOxygen cylinder scale is\nEnter 0 for very low\n1 for low\n2 for medium\n3 for high\n\n";
    for(int i=0;i<n-1;i++)
    {
        cout<<"Enter oxygen level of "<<hospitals[i]<<" ("<<i+2<<"):";
        cin>>priority[i];

    }
    cout<<"\n\nThe path is:\n\n";
    for(int i=0;i<n-1;i++)
    {

        if(priority[i]==0)     //first priority if oxygen is very low
        {
            printf("%d -->",i+2);
            visited[i+1]=1;


        }
    }
    for(int i=0;i<n-1;i++)
    {
    if(priority[i]==1)   //second priority if oxygen is  low
        {
            printf("%d -->",i+2);
            visited[i+1]=1;

        }
    }

}


void put()
{
	cout<<"\n\nMinimum distance:\n";
	cout<<fixed<<setprecision(1)<<cost;
}

int main()
{
    ifstream file;
    file.open("file.txt");
    int number[20][20];

    if(file.is_open())
    {
            cout << "File Opened successfully!!!. Reading data from file into array";
            while(!file.eof())
            {
                    for(int i = 0; i < n; i++)
                    {
                            for(int j = 0; j < n; j++)
                            {
                                    //level[i][j] = ???
                                    file >> number[i][j];
                                    cout << number[i][j];
                            }
                            cout << endl;
                    }
            }

    }
    else

    file.close();
    cout<<"\t\t\t--Welcome to Oxygen Delivery System--";
    cout<<"\n\nThe oxygen Delivery Van always starts from Place 1,and hospitals are labelled as 2,3,4 etc. and the van always returns to 1 after finishing delivery\n\n";
	get();
	level();
	mincost(0);
	put();
	return 0;
}