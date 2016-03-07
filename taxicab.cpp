#include<iostream>
#include<fstream>
#include<cmath>
#define maxlistsize 100
using namespace std;
struct point{
    double x;
    double y;
};
double cal_dis(point location1,point location2){
    return abs(location1.x-location2.x)+abs(location1.y-location2.y);
}
int main(){
    point location_list[maxlistsize],mylocation;
    ifstream infile;
    string infilename;
    double tmpx,tmpy,distance;
    int listsize,closest_index;
    cout<<"Please enter the file of locations"<<endl;
    getline(cin,infilename);
    infile.open(infilename.c_str());
    if(!infile.good()) {
        cout<<"File can not be opened"<<endl;
        return 0;
    }
    for(listsize=0;infile.good();listsize++){
        infile>>tmpx>>tmpy;
        location_list[listsize].x=tmpx;
        location_list[listsize].y=tmpy;
    }
    cout<<"Please enter your location"<<endl;
    cin>>mylocation.x>>mylocation.y;
    
    distance=cal_dis(mylocation,location_list[0]);
    closest_index=0;
    for(int i=1;i<=listsize;i++){
        if(cal_dis(mylocation,location_list[i])<distance) closest_index=i;
    }
    cout<<"The closest point from your location is ("<<location_list[closest_index].x<<", "<<location_list[closest_index].y<<")"<<endl;
    return 0;
}