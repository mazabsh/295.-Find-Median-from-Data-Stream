#include<iostream> 
#include<queue> 

using namespace std; 

class MedianFinder{
public: 
     priority_queue<int> left; 
     priority_queue<int, vector<int> , greater<>> right; 
     MedianFinder(){}
     void addNum(int num){
       if(left.empty()|| num<= left.top()) left.push(num); 
       else right.push(num); 

       if(left.size() > right.size()+1){
         right.push(left.top()); 
         left.pop(); 
       }else if( right.size()>left.size()) {
         left.push(right.top()); 
         right.pop(); 
       }
     }
     double findMedian(){
       if(left.size()==right.size()) return (left.top()+right.top())/2.0; 
       else return left.top(); 
     }
};
int main(){
    MedianFinder medf; 
    medf.addNum(5); 
    medf.addNum(10); 
    medf.addNum(2); 
    medf.addNum(6); 
    medf.addNum(8); 
    cout << medf.findMedian() << endl; 
    return 0; 
}
