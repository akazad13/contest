
//res is an array of big number
void multiply(long long int n)
{
    int SIZE = res.size();
    long long int carry=0;
    for(int i=0;i<SIZE;i++)
    {
        carry+=res[i]*n;
        //cout<<carry<<endl;
        res[i]=carry%10;
        carry/=10;
    }
    while(carry)
    {
        res.push_back(carry%10);
        carry/=10;
    }
 
}
