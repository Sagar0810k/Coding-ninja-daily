int totalSteps(int n, int k, vector<int> &flowers) {
    //    Write your code here
    int water=k;
    int steps=0;
    for(int i=0;i<n;i++){
        if(water<flowers[i]){
            steps+=2*i;
            water=k;
        }
        steps++;
        water-=flowers[i];
    }
    return steps;

}