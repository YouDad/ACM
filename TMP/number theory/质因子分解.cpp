#define factype std::vector<int>
factype findfac(int num){
    factype v;
    int i=2;
    if(num%2==0)
        v.push_back(2);
    while(num%2==0)num/=2;
    for(i=3;i<=num/2;i+=2){
        while(num>=i){
            if(num%i==0){
                if(num/i==1)
                    v.push_back(i);
                else
                    v.push_back(i);
                num/=i;
            }else
                break;
        }
    }
    if(num!=1)
        v.push_back(num);
    return v;
}