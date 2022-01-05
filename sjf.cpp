#include <iostream>
using namespace std;
int mat[10][6];
void arrangeArrival(int num, int mat[][6])
{
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mat[j][1] > mat[j + 1][1]) {
				for (int k = 0; k < 5; k++) {
					int temp = mat[j][k];
	                 mat[j][k]= mat[j + 1][k];
	                  mat[j + 1][k]= temp;
				}
			}
		}
	}
}

void Timecalculation(int num, int mat[][6])
{
	int temp, val;
	mat[0][3] = mat[0][1] + mat[0][2];   //CT=AT+BT
	mat[0][5] = mat[0][3] - mat[0][1];   //TAT=CT-AT
	mat[0][4] = mat[0][5] - mat[0][2];   //WT=TAT-BT

	for (int i = 0; i < num; i++) {
		temp = mat[i - 1][3];
		int low = mat[i][2];
		for (int j = i; j < num; j++) {
			if (temp >= mat[j][1] && low >= mat[j][2]) {
				low = mat[j][2];
				val = j;
			}
		}
		mat[val][3] = temp + mat[val][2];
		mat[val][5] = mat[val][3] - mat[val][1];
		mat[val][4] = mat[val][5] - mat[val][2];
		for (int k = 0; k < 6; k++) {
			int temp = mat[val][k];
	         mat[val][k]= mat[i][k];
	          mat[i][k]= temp;
		}
	}
}

int main()
{
	int num, temp,total_tat=0,total_wt=0,avg_tat=0,avg_wt=0;

	cout << "Enter number of Process: ";
	cin >> num;

	for (int i = 0; i < num; i++) {
	cout << "...Process " << i + 1 << "...\n";
	cout << "Enter Process Id: ";
		cin >> mat[i][0];
		cout << "Enter Arrival Time: ";
		cin >> mat[i][1];
		cout << "Enter Burst Time: ";
		cin >> mat[i][2];
	}

	cout << "Before Arrange...\n";
	cout << "Process ID\tArrival Time\tBurst Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\n";
	}

	arrangeArrival(num, mat);

	Timecalculation(num, mat);
	cout << "Final Result...\n";
	cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting "
			"Time\tTurnaround Time\n";
	for (int i = 0; i < num; i++) {
		cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
			<< mat[i][2] << "\t\t" <<mat[i][3]<<"\t\t"<< mat[i][4] << "\t\t"
			<< mat[i][5] << "\n";
            total_tat=total_tat+mat[i][5];
            total_wt=total_wt+mat[i][4];
	}
    cout<<"Average Turn Around Time= "<<float(total_tat)/float(num)<<endl;
    cout<<"Average Waiting Time= "<<float(total_wt)/float(num);
    return 0;
}
