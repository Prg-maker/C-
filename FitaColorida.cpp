#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>


using namespace std;

int d(int xs[] , int index ){
	int  r = -1;

	for(int i = index ; i >= 0 ; i--){
		if(xs[i] == 0){
			r = i;
			
			break;
		}
	}
	return r;

}
int m (int xs[], int index, int t){
	int r = -1;

	for(int i = index; i<t ; i++){
		if(xs[i] == 0){
			r = i;
			break;
		}
	}

	return r;
}

void solve(int xs[], int t){
	int r = 0  , p= 0;
	
	int res[t];
	for(int i = 0 ; i < t ; i++){
		if(xs[i] == 0)res[i] = xs[i];
		else res[i] = 1;
	}

		
	int k = 0;
	int c = 0;
	for(int i = 0 ; i < t ; i++){
		if(res[i] != 0){
			p = d(res , i); 
			r= m(res, i , t);

			if(p != -1 && r!= -1){
							
				k = p;

				if(abs(r - i) < abs( p-i)) k = r;
					
			  	
				c = abs(k-i);
			}else{
				k = max(p , r);
				
				c = abs(k-i);
			}
			if(c >= 9 ) c = 9 ; 
			res[i] = c;
		}

	}


	for(int i = 0 ; i < t ; i++){

		cout << res[i] << " ";
	}
}

int main(){
		int x ;

		cin >> x;
		
		int xs[x];

		for(int i = 0 ; i < x ; i++) cin >> xs[i];
		
		solve(xs , x);
}
