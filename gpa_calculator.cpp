#include<iostream>
using namespace std;

//SGPA calculator
void cal_SGPA()
{
	int subj;
	double crd_hrs[subj];
	double pnt[subj];
	double sum_p = 0;
	double total;
	double totalcrd = 0;
	
	
	cout<<"\nFor calculating SGPA \nEnter number of subjects : ";
	cin>>subj;
	
	cout<<"\nEnter Credit hours and Points of each subject\n\n";
	
	for(int i=1; i <= subj ; i++)
		{
			cout<<"\nSubject "<<i<<endl;
			
			cout<<"\nCredit Hours : ";
			cin>>crd_hrs[i];
			
			cout<<"\nPoints : ";
			cin>>pnt[i];
			
			cout<<"\n------------------------------------------\n";
		}
		
		
	for(int i=0; i < subj ; i++)
		{
			total = crd_hrs[i] * pnt[i];
			sum_p += total ;
		}
		
		
	for(int i=0; i < subj ; i++)
		{
			totalcrd += crd_hrs[i];
		}
		
	cout<<"\n\nTotal points : "<<sum_p;	
	cout<<"\nTotal Credits : "<<totalcrd<<endl;
	cout<<"SGPA : "<< sum_p/totalcrd << endl;
		
}

//CGPA calculator
void cal_CGPA()
{
	int sem;
	double gpa[sem];
	double semTotal = 0;
	cout<<"\nCGPA calculator\n\n";
	cout<<"\nFor calculating CGPA \nEnter number of semesters : ";
	cin>>sem;
	
	for(int i=1; i<=sem; i++)
		{
			cout<<"\nEnter GPA for Semester "<<i<<" : ";
			cin>>gpa[i];
		}
		
	for(int i=1; i<=sem; i++)
		{
			semTotal += gpa[i];
		}
		
		cout<<"\nCGPA : "<< semTotal/sem;
		cout<<endl;
	
}

int main()
{
	do
	{
		cout<<"\033[32m\t\t\tGPA CALCULATOR\033[0m\n";
		cout<<"\nDo you want to\n";
		cout<<"1. Calculate SGPA\n";
		cout<<"2. Calculate CGPA\n";
		cout<<"3. Exit\n\n";
		cout<<"Your choice : ";
		int ch;
		cin>>ch;
		cout<<endl<<endl;
		
		if(ch == 1)
			{
				cal_SGPA();
			}
			
		else if(ch == 2)
			{
				cal_CGPA();
			}
			
		if(ch == 3)
			{
				exit(0);
			}
		
		
	}while(1);
	
	
	return 0;
}