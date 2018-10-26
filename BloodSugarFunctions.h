#pragma once
// BloodSugarFunctions.h
// Jacob Silva
// Project 1
//COSC 2030
double daySum(List x)
{
	double sum = 0;
	sum = x.sum();
	return sum;
}

double dayMax(List x)
{
	double max = 0;
	max = x.max();
	return max;
}

double dayMin(List x)
{
	double min = 0;
	min = x.min();
	return min;
}

double countValidIn(List x)
{
	double count = 0;
	count = x.size();
	return count;
}

void daySummary(List x)
{
	cout << "Daily Summary" << endl << "Sum :" << daySum(x) << endl;
	cout << "Max: " << dayMax(x) << " Min: " << dayMin(x) << endl;
	cout << "Count of Valid Readings: " << countValidIn(x) << endl;
}

double weekSum(List x[], int currDay)
{
	double total = 0;
	for (int i = 0; i <= currDay; i++)
	{
		List y = x[i];
		total=total+y.sum();
	}
	
	return total;
}

double weekMax(List x[], int currDay)
{
	double total = 0, max = 0;
	
	for (int i = 0; i <= currDay; i++)
	{
		List y = x[i];
		if (max < y.max())
		{
			max = y.max();
		}
	}
	total = max;
	return total;
}

double weekMin(List x[], int currDay)
{
	
	double total = 0, min = x[0].min();

	for (int i = 1; i <= currDay; i++)
	{
		List y = x[i];
		if (min > y.min())
		{
			min = y.min();
		}
	}
	total = min;
	return total;
}

double weekCount(List x[], int currDay)
{
	double total = 0, temp = 0;

	for (int i = 0; i <= currDay; i++)
	{
		List y = x[i];
		temp = temp + y.size();
	}
	total = temp;
	return total;
}

double weekDelta(List x[], int currDay)//CALCULATES THE LARGEST DELTA FROM DAY TO DAY OF VALID READINGS
{
	
	double total = 0,diff=(x[1].size()-x[0].size()),diff2=0,temp=0,temp2=0;
	if (currDay == 0)
	{
		diff = 0;
	}
	if (currDay > 1)
	{
		for (int i = 1; i <= currDay; i++)
		{
			List y = x[i];
			List z = x[i - 1];
			temp = y.size();
			temp2 = z.size();
			diff2 = temp - temp2;
			if(diff2<0)
			{
				diff2 = diff2 * -1;
			}
			if (diff<diff2)
			{
				diff = diff2;
	
			}
		}
	}
	if (diff < 0)
	{
		diff = diff * -1;
	}
	total = diff;
	return total;
}

double deltaDay(List x[], int currDay)// RETURNS THE DAY OF THE HIGHEST DELTA OF VALID READINGS
{

	double  diff = (x[1].size() - x[0].size()), diff2 = 0, temp = 0, temp2 = 0,day=0;
	if (currDay == 0)
	{
		diff = 0;
	}
	if (currDay > 1)
	{
		for (int i = 1; i <= currDay; i++)
		{
			List y = x[i];
			List z = x[i - 1];
			temp = y.size();
			temp2 = z.size();
			diff2 = temp - temp2;
			if (diff2<0)
			{
				diff2 = diff2 * -1;
			}
			if (diff<diff2)
			{
				diff = diff2;
				day = i;
			}
		}
	}
	
	return day;
}

string Day(int currDay)
{
	switch (currDay)
	{
	case 0: return "Monday"; break;
	case 1: return  "Tuesday"; break;
	case 2: return "Wednesday"; break;
	case 3: return "Thursday"; break;
	case 4: return "Friday"; break;
	case 5: return "Saturday"; break;
	case 6: return "Sunday"; break;
	case 7: return "Monday"; break;
	case 8: return  "Tuesday"; break;
	case 9: return "Wednesday"; break;
	case 10: return "Thursday"; break;
	case 11: return "Friday"; break;
	case 12: return "Saturday"; break;
	case 13: return "Sunday"; break;
	}


}

void weekSummary(List x[], int currDay)
{
	int y = deltaDay(x, currDay);
	cout << "Weekly Summary" << endl << "Sum :" << weekSum(x,currDay) << endl;
	cout << "Max: " << weekMax(x,currDay) << " Min: " << weekMin(x,currDay) << endl;
	cout << "Largest Delta of Valid Readings: " << weekDelta(x, currDay) << " | Day: " << Day(y) << endl;
	cout << "Count of all Valid Readings: " << weekCount(x, currDay) << endl;
}