
import java.io.*;
import java.util.Scanner;

class Solution {
    
    public static int partition(int ar[], int start, int end){
        int pivot = ar[end];
        int i = start;
        for(int j= start;j<end;j++){
            if(ar[j]<pivot){
                int temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
                i++;
            }
        }
        int temp = ar[i];
        ar[i] = ar[end];
        ar[end] = temp;
        return i;
        
    }
    
    public static void quickSort(int ar[], int start, int end){
        if(start<end){
            int pivot = partition(ar, start, end);
            quickSort(ar, start, pivot-1);
            quickSort(ar, pivot+1, end);
        }
    }
    
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int n= sc.nextInt();
	    int ar[] = new int[n];
	    for(int i=0;i<n;i++){
	        ar[i] = sc.nextInt();
	    }
	    quickSort(ar, 0, n-1);
	    for(int i: ar)
	        System.out.print(i+" ");
	}
}
