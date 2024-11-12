class MedianFinder {
public:
    //左边大顶堆，右边小顶堆，小的加左边，大的加右边，平衡俩堆数，新加就弹出，堆顶给对家，奇数取多的，偶数取除2.
    priority_queue<int> left;//大根堆
    priority_queue<int,vector<int>,greater<int>> right;//小根堆
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(left.size()==right.size()){
            if(left.empty()||num<=left.top())//放left里面
            {
                left.push(num);
            }
            else{
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else{
            if(num<=left.top()){
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else{
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size()==right.size())return (left.top()+right.top())/2.0;
        else{
            return left.top();
        }
    }
};
