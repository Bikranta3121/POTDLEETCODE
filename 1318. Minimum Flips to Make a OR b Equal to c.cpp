class Solution {
public:
    void get_binary(vector<int> &arr,int x)
    {
        while(x)
        {
            arr.push_back(x&1);
            x>>=1;
        }
    }
    void push_zero(vector<int> &x,int zeros)
    {
         while(zeros--)
         {
             x.push_back(0);
         }
    }
    int minFlips(int a, int b, int c) {
       vector<int>A,B,C;
       get_binary(A,a);
       get_binary(B,b);
       get_binary(C,c);
       if(A.size()>B.size())
       {
           push_zero(B,A.size()-B.size());
       }
       if(A.size()<B.size())
       {
           push_zero(A,B.size()-A.size());
       }
       if(A.size()>C.size())
       {
           push_zero(C,A.size()-C.size());
       }
       if(A.size()<C.size())
       {
           push_zero(A,C.size()-A.size());
           push_zero(B,C.size()-B.size());
       }
       int count=0;
       for(int i=0;i<C.size();i++)
       {
           if(C[i] and !A[i] and !B[i])
           {
               count+=1;
           }
           else if(!C[i] and A[i] and B[i])
           {
               count+=2;

           }
           else if(!C[i] and (A[i] || B[i]))
            count+=1;
       }
       return count;
        

    }
};
