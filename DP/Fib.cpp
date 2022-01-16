 int fib(int n) {

        if(n < 2)
            return n;

        //Tabulation or bottom up
       //
        int Fib_1 = 0;
        int Fib_2 = 1;
        int Fib_n;

        for(int i = 2; i<=n; i++)
        {
            Fib_n = Fib_1 + Fib_2;

            Fib_1 = Fib_2;

            Fib_2 = Fib_n;

        }

        return Fib_n;

    }
