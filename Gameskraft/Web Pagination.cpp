int parameter=-1;
int Order=-1;

bool compr(vector<string> &a,vector<string> &b){
    if(parameter==0){
        if(Order==0){
            return a[0]<b[0];
        }
        else{
            return a[0]>b[0];
        }
    }
    else
    if(parameter==1){
        if(Order==0){
            return stoi(a[1])<stoi(b[1]);
        }
        else{
            return stoi(a[1])>stoi(b[1]);
        }
    }
    else{
        if(Order==0){
            return stoi(a[2])<stoi(b[2]);
        }
        else{
            return stoi(a[2])>stoi(b[2]);
        }
    }
}

vector<string>fetchItemsToDisplay(vector<vector<string>> &items,int Par,int O,int PerPage,int pageNo){
    parameter=Par;
    Order=O;
    int n=items.size();
    sort(items.begin(),items.end(),compr); 
    vector<string>ans;
    
    int i = pageNo * PerPage;
    int j = min(n, i+PerPage);
    for(int k=i; k<j; k++) {
        ans.push_back(items[k][0]);
    }
    return ans;
}

int main(){
    vector<vector<string>>items;
    items.push_back(vector<string>{"item1","10","15"});
    items.push_back(vector<string>{"item2","3","4"});
    items.push_back(vector<string>{"item3","17","8"});
    items.push_back(vector<string>{"item4","7","18"});
    items.push_back(vector<string>{"item5","1","3"});
    items.push_back(vector<string>{"item6","12","4"});
    int sortPar=2;
    int sortOrder=1;
    int itemsPerPage=2;
    int pageNumber=1;
    vector<string>ans=fetchItemsToDisplay(items,sortPar,sortOrder,itemsPerPage,pageNumber);
    for(auto &x:ans)
        cout<<x<<" ";
    return 0;
}
