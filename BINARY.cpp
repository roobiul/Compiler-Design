#include <iostream>
using namespace std;
int main()
{
int n;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++)
cin >> arr[i];
int target;
cout << "Enter Target: ";
cin >> target;
int low = 0;
int high = n - 1;
int mid;
while(low <= high)
{
mid = low + (high - low) / 2;
if(arr[mid] == target)
{
cout << "Element found at index " << mid << endl;
return 0;
}
else if(arr[mid] < target)
{
low = mid + 1;
}
else
{
high = mid - 1;
}
}
cout << "Element not found" << endl;
return 0;
}
