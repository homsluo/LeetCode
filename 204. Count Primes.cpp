//
// Created by homsl on 2020/5/13.
//
int countPrimes(int n) {
    if(n < 3)
        return 0;
    vector<int> primes(n,1);
    primes[0] = primes[1] = 0;
    for(int i = 2; i < sqrt(n); i++){
        if(!primes[i])
            continue;
        for(int j = i*i; j < n; j+=i)
            primes[j] = 0;
    }
    return accumulate(primes.begin(), primes.end(), 0);
}
