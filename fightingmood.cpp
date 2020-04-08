#include <bits/stdc++.h>

using namespace std;


class fightingmood{
	string questions[10];
	string options[6];
	float factor[6];
	float happiness;
	public:
		fightingmood(){
			happiness=0;
			questions[0]="I feel luck plays an important role in happiness";
			questions[1]="I rarely wake up feeling rested";
			questions[2]="I feel that life is very rewarding";
			questions[3]="I am always committed and involved";
			questions[4]="There is a gap between what I would like to do and what I have done";
			questions[5]="I feel that I am not especially in control of my life";
			questions[6]="I find it easy to make decisions";
			questions[7]="I have a particular sense of meaning and purpose in my life";
			questions[8]="I am well satisfied about everything in my life";
			questions[9]="I think that my happiness is directly linked to the amount of material possessions and wealth that I have";
			options[0]="1.strongly disagree";
			options[1]="2. moderately disagree";
			options[2]="3.slightly disagree";
			options[3]="4.slightly agree";
			options[4]="5.moderately agree";
			options[5]="6.strongly agree";
			factor[0]=1;
			factor[1]=2;
			factor[2]=4;
			factor[3]=6;
			factor[4]=8;
			factor[5]=9;
		}
		void display(){
			cout<<" Welcome to Fighting mood\n";
			int choice;
			for(int i=0;i<10;i++){
				cout<<questions[i]<<endl;
				for(int j=0;j<6;j++){
					cout<<options[j]<<"\t";
				}
				cout<<endl;
				cin>>choice;
					happiness+=factor[choice-1];
				cout<<endl;
			}
		}
		int result(){
			cout<<"Your happiness score is "<<(happiness)<<" %\n";
			return happiness;
		}
		
};
int sum=0;
vector<int> v;
void printknapSack(int W, int wt[], int val[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    //dp of knapsack yay!!!
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max(val[i - 1] +  
                    K[i - 1][w - wt[i - 1]], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
   int res = K[n][W];     
    ///cout<<res; 
      
    w = W; 
    for (i = n; i > 0 && res > 0; i--) { 
          
       
        if (res == K[i - 1][w])  
            continue;         
        else { 
  
            v.push_back(i);
            sum=max(sum,val[i-1]);
         
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    } 
  //  cout<<endl<<sum;
} 

int main(){
	fightingmood f;
	f.display();
    int p=	f.result();
    int percentage=100-p;
    //clrscr();
     int val[] = { 45, 30, 60,30,25 }; //time period this is what we need to maximize as we want to support the person as long as we could at max 60 days ie 2 months package
    int wt[] = { 1,3,2,3,1}; //these are the percentage associated with each advice according to their effectiveness the have been divided by 10 by me i felt easy solving like that
    int W = floor(percentage/10) ;
    int n = 5;
    string str[5]={
	               "*) . Regular sleep Balance needed \n7-8 hours required for being healthyboth mentally and physically .\nCommon medicines might not work if sleep pattern is not changed \n*Suggestions to have a good sleep at night *:\nA)naps needed during the day : limit it to 20-30 mins only\nB) limit alcohol and caffeine\nC) avoid spicy food close to bed time .\nD) do not talk about stressful things right before sleep.",
                   "*) . Better your relationships\ntry to stay connected with your loved ones.\nCalling a friend or going for a walk immediately boosts mood and releases feel good hormones.\nMake face time a priority twice a week",
				   "*) . Do things that makes you feel good\nDo this once a week for next 2 months.\nDiscover yourself and your passion and take out time for your favourite thing ",
				   "*) . Eat healthy\ndonot skip meals .\nBoost vitamin B intake ( deficiency can trigger depression) and get that sunlight every day.",
				   "*) . Excercise daily\naim for at least 30 minutes of exercise per day\nA 10-minute walk can improve your mood for two hours" };
	             
    printknapSack(W, wt, val, n); 
    cout<<"_________________________________________________________________________________________________________\n";
    cout<<"\t\t\t\tbright sun is waiting for you!\n\t\t\t\tHere we are providing you with "<<sum<<" days package\n";
    cout<<"\t\t\t\tfollow this up and you will meet brighter you!\n";
    for(int i=0;i<v.size();i++)
    {
    	cout<<str[v[i]-1];
    	cout<<endl;
    	cout<<"*********************************************************************************************************\n";
    	
	}
    cout<<"_________________________________________________________________________________________________________\n"; 
	
	return 0;
}
