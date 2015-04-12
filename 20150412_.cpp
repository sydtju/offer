	bool Find(vector<vector<int> > array,int target) {
		int start=0;
 int end=array.size()-1;
 int i=0;
 vector<int>::iterator it1;
 i=0;
 while(i!=(start+end)/2){
	 i=(start+end)/2;		 
	 if(array[i].front()>target){
		 end=i;
	 }
	 else if(array[i].front()==target){
		 //cout<<"find"<<endl;
		 return true;
	 }
	 else{
		 start=i;
	 }
 }
 for(int j=end;j>=0;j--){
	 end=array[j].size()-1;
	 start=0;
	 i=0;
	 it1=array[j].begin();
	 if((*(it1+end))==target) {return true;}//cout<<"find"<<endl;
	 while(i!=(start+end)/2){
		 i=(start+end)/2;
		 if((*(it1+i))>target){
			 end=i;
		 }
		 else if((*(it1+i))==target){
			// cout<<"find"<<endl;
			 return true;
		 }
		 else{
			 start=i;
		 }
		 }
	 }
	 return false;
	}
