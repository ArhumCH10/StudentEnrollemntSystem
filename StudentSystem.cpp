#include<iostream>
using namespace std;

float checkMarks(float k){
	if (k<=100&&k>=0)
	{
		return k;
	}
	else
	{
		float marks;
		while (1)
		{			
			cout << "Enter the Marks within 100 :"; cin >> marks;
			if (marks <= 100 && marks >= 0)
			{
				break;
			}
		}
		return marks;
	}
}
void OperationsMenu(){
	cout << endl;
	cout << "1.\tPress 1 to Update Roll Number of a particular Student.\n";
	cout << "2.\tPress 2 to Update Marks of a particular Student or CS.\n";
	cout << "3.\tPress 3 to Update marks of CS for all Student who are already enrolled.\n";
	cout << "4.\tPress 4 to Update Marks of Mathematics of particular Student.\n";
	cout << "5.\tPress 5 to Update Marks of Mathematics for all Student who are already enrolled.\n";
	cout << "6.\tPress 6 to Sort the data on the basis of generated percentages.\n";
	cout << "7.\tPress 7 to delete the record of a particular student.\n";
}
void CalulatePercentage(int *RollNumbers,float *ComputerMarks,float *MathMarks,float *Percentage,char *grade,int size){
	for (int i = 0; i < size; i++)
	{
		if (RollNumbers[i] != 0 && MathMarks[i] != 0 && Percentage[i] != 0 && ComputerMarks[i] != 0)
		{
			float sum = MathMarks[i] + ComputerMarks[i];
			Percentage[i] = (sum / 200) * 100;
		}
	}
}
void CalculateGrade(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	for (int i = 0; i < size; i++)
	{
		if (RollNumbers[i] != 0 && MathMarks[i] != 0 && Percentage[i] != 0 && ComputerMarks[i] != 0)
		{
			if (Percentage[i] < 50)
			{
				grade[i] = 'F';
			}
			else if (Percentage[i] >= 50 && Percentage[i] < 60)
			{
				grade[i] = 'D';
			}
			else if (Percentage[i] >= 60 && Percentage[i] < 75)
			{
				grade[i] = 'C';
			}
			else if (Percentage[i] >= 75 && Percentage[i] <= 95)
			{
				grade[i] = 'B';
			}
			else
			{
				grade[i] = 'A';
			}
		}
	}
}
void display(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	CalulatePercentage(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
	CalculateGrade(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (RollNumbers[i] != 0 && MathMarks[i] != 0 && Percentage[i]!= 0 && ComputerMarks[i] != 0)
		{
			cout << "Roll number of student " << i + 1 << ": " << RollNumbers[i] << endl;
			cout << "Marks of Computer Science of Student " << i + 1 << " is : " << ComputerMarks[i] << endl;
			cout << "Marks of Math of Student " << i + 1 << " is : " << MathMarks[i] << endl;
			cout << "Percentage of Student " << i + 1 << " is : " << Percentage[i]<<"%" << endl;
			cout << "Grade of Studen " << i + 1 << " is : " << grade[i] << endl;
			cout << endl;
		}
	}

}
void updateRollNum(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	cout << "Enter Old Roll Number :";
	int roll; cin >> roll;
	bool flag = false; int index;
	for (int i = 0; i < size; i++)
	{
		if (roll==RollNumbers[i])
		{
			flag = true;
			index=i;
		}
	}
	if (!flag)
	{
		cout << "Roll number not found\n";
	}
	else
	{
		cout << "Enter new Roll Number : ";
		cin >> RollNumbers[index];
		cout << "Updated Successfully\n";
	}
}
void UpdateMarksOfComputer(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	cout << "Enter Roll Number :";
	int roll; cin >> roll;
	bool flag = false; int index;
	for (int i = 0; i < size; i++)
	{
		if (roll == RollNumbers[i])
		{
			flag = true;
			index = i;
		}
	}
	if (!flag)
	{
		cout << "Roll number not found\n";

	}
	else
	{
		cout << "Enter Marks of Computer Science:";
		cin >> ComputerMarks[index];
		CalulatePercentage(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
		CalculateGrade(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
		cout << "Updated Succecsully\n";

	}
}
void UpdateMarksOfCSforAllStudent(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	for (int i = 0; i < size; i++)
	{
		if (RollNumbers[i] != 0 && MathMarks[i] != 0 && Percentage[i] != 0 && ComputerMarks[i] != 0)
		{
			cout << "Enter Marks of Computer Science of Student " << i + 1 << " within 100 : ";
			cin >> ComputerMarks[i];
		}
	}
	CalulatePercentage(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
	CalculateGrade(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
	cout << "Updated SuccesFully\n";
}
void UpdateMarksOfMathematics(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	cout << "Enter Roll Number :";
	int roll; cin >> roll;
	bool flag = false; int index;
	for (int i = 0; i < size; i++)
	{
		if (roll == RollNumbers[i])
		{
			flag = true;
			index = i;
		}
	}
	if (!flag)
	{
		cout << "Roll number not found\n";

	}
	else
	{
		cout << "Enter Marks of Mathematics :";
		cin >> MathMarks[index];
		CalulatePercentage(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
		CalculateGrade(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
		cout << "Updated Succecsully\n";

	}
}
void UpdateMarksOfMathForAllStudent(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	for (int i = 0; i < size; i++)
	{
		if (RollNumbers[i] != 0 && MathMarks[i] != 0 && Percentage[i] != 0 && ComputerMarks[i] != 0)
		{
			cout << "Enter Marks of Computer Science of Student " << i + 1 << " within 100 : ";
			cin >> MathMarks[i];
		}
	}
	CalulatePercentage(RollNumbers, ComputerMarks, MathMarks, Percentage, grade,  size);
	CalculateGrade(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, size);
	cout << "Updated SuccesFully\n";
}
void DeleteStudentRecord(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	cout << "Enter Roll Number :";
	int roll; cin >> roll;
	bool flag = false; int index;
	for (int i = 0; i < size; i++)
	{
		if (roll == RollNumbers[i])
		{
			flag = true;
			index = i;
		}
	}
	if (!flag)
	{
		cout << "Roll number not found\n";
	}
	else
	{
		RollNumbers[index] = 0;
		ComputerMarks[index] = 0;
		MathMarks[index] = 0;
		Percentage[index] = 0;
		grade[index] = '\0';
		cout << "Deleted SuccesFully\n";
	}
}
void SortStudents(int *RollNumbers, float *ComputerMarks, float *MathMarks, float *Percentage, char *grade, int size){
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (Percentage[i] <Percentage[i] )
			{
				int temproll;float tempCS, tempM, tempPer; char tempGrade;
				temproll = RollNumbers[i];
				tempCS = ComputerMarks[i];
				tempM = MathMarks[i];
				tempPer = Percentage[i];
				tempGrade = grade[i];

				RollNumbers[i] = RollNumbers[j];
				ComputerMarks[i] = ComputerMarks[j];
				MathMarks[i] = MathMarks[j];
				Percentage[i] = Percentage[j];
				grade[i] = grade[j];
				
				RollNumbers[j]=temproll;
				ComputerMarks[j]=tempCS;
				MathMarks[j]=tempM;
				Percentage[j]=tempPer;
				grade[j]=tempGrade;
			}
		}
	}

}

int main(){

	cout << "~~~~~~~~~~~~~~~( WELCOME TO ADMIN PANEL )~~~~~~~~~~~~~~~~\n";
	cout << "Enter Roll Numbers and their data to enroll studends!\n";
	int RollNumbers[5] ;
	float ComputerMarks[5], MathMarks[5], Percentage[5]; char grade[5] = { '\0' };
	int index = 0; char ch='\0';
	do
	{
		float marks;
		cout << "Enter Roll number of student " << index + 1 << ": ";
		cin>>RollNumbers[index];
		cout << "Enter Marks of Computer Science of Student " << index + 1 << " within 100 : ";
		cin >> marks;
		ComputerMarks[index] = checkMarks(marks);
		cout << "Enter Marks of Math of Student " << index + 1 << " within 100 : ";
		cin >> marks;
		MathMarks[index] = checkMarks(marks);
		index++;
		if (index<5)
		{
			cout << "Enter Y/y to continue adding students and their data and N/n to stop :"; cin >> ch;
		}
		if (index==5||ch=='n'||ch=='N')
		{
			break;
		}
			
	} while (1);
	
	OperationsMenu();

	cout << "\nDo you want to perform any of the following operatons?\n";
	cout << "Press Y/y for yes.\n";
	cout << "Press N/n for No.\n";
	cout << "Enter your choice :"; char choise; cin >> choise;
	if (choise == 'N'||choise=='n')
	{
		display(RollNumbers,ComputerMarks,MathMarks,Percentage,grade, index);
	}
	else
	{

		cout << "Select Option :"; int c;
		cin >> c;
		if (c == 1)
		{
			updateRollNum(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 2)
		{
			UpdateMarksOfComputer(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 3)
		{
			UpdateMarksOfCSforAllStudent(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 4)
		{
			UpdateMarksOfMathematics(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 5)
		{
			UpdateMarksOfMathForAllStudent(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 6)
		{
			SortStudents(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else if (c == 7)
		{
			DeleteStudentRecord(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
		}
		else
		{
			cout << "Invalid Entry\n";
		}
		display(RollNumbers, ComputerMarks, MathMarks, Percentage, grade, index);
	}
	

}