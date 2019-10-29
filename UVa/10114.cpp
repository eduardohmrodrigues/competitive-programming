#include <cstdio>

int main(){
	double records[100];
	int m, r, dr;
	double dp, t, drv, monthly;
	
	while(scanf("%d %lf %lf %d", &m, &dp, &t, &r) && m > 0){
		monthly = t/m;
		t += dp;
		int index = 0;
		for(int i=0; i<r; i++){
			scanf("%d %lf", &dr, &drv);
			for(int j=index; j<dr; j++, index++){
				records[j] = records[index-1];
			}
			records[index] = drv;
			index++;

			if(i == r-1 && r < m){
				for(int j=index; j<=m; j++, index++){
					records[j] = drv;
				}
			}
		}
		
		//printf("Car Total Value: %lf | Depreciated Value: %lf | Monthly: %lf\n", t, t-t*records[0], monthly);
		int mCompensate = 0;
		t = t-t*records[0];
		for(int i=0; i<=m; i++, mCompensate++){
			if (i > 0) t = t-t*records[i];
			//printf("Month %d: Car Value = %lf | YetToPay: (%lf)  Depreciation of: %lf%%\n", i, t, monthly*(m-i), records[i]);
			if(monthly*(m-i) < t){
				break;
			}
		}
		
		if(mCompensate == 1) printf("%d month\n", mCompensate);
		else printf("%d months\n", mCompensate);
	}
		
	return 0;
}
