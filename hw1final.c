#include <stdio.h>
#include <math.h>
#include <assert.h>

//-----------------------------------------------------------------------------
//{============================================================================
//! This fuction solves square equation ax^2 + bx + c = 0
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! 
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @return Number of roots
//}============================================================================

int SolveSquare(double a, double b, double c,
                double* x1, double* x2)
{
        assert(isfinite (a));
        assert(isfinite (b));
        assert(isfinite (c));

        assert(x1 != NULL);
        assert(x2 != NULL);
        assert(x1 != x2);

        if(a == 0)
        {
                if(b == 0)
                {
                        return (c == 0)? 3 : 0;
                }
                else
                {
                        *x1 = - c / b;
                        return 1;
                }
        }
        else
        {
                double d = b * b - 4 * a * c;
                if(d < 0)
                        return 0;
                else if(d == 0)
                {
                        *x1 = *x2 = (- b) / (2 * a);
                        return 1;

                }
                else if(d > 0)
                {
                        *x1 = (- b + sqrt(d)) / (2 * a);
                        *x2 = (- b - sqrt(d)) / (2 * a);
                        return 2;
                }
        }
        return -1;
}

//-----------------------------------------------------------------------------
//{============================================================================
//! This fuction prints roots of square equation
//! @param [in] Nroots Nroots-number of roots of square equation
//! @param [in] x_1    x_1 - first root
//! @param [in] x_2    x_2 - second root
//! 
//!
//! @note This function prints "No roots" - in case if this equation has no roots,
//!                            "x = ..." - in case if this equation has only one root,
//!                            "x1 = ..., x2 = ..." - in case if this equation has two roots,
//!                            "Infinite number of solutions" - in case if any number is a root
//}============================================================================

void PrintRoots(int Nroots, double x1, double x2)
{
        printf(" ");
        switch(Nroots)
        {
                case 0: printf(" NO roots\n ");
                        break;

                case 1: printf(" x = %lg\n ", x1);
                        break;

                case 2: printf(" x1 = %lg, x2 = %lg\n ", x1, x2);
                        break;

                case 3: printf("Infinite number of solutions");
                        break;
        }
        return;

}

//-----------------------------------------------------------------------------
//{============================================================================
//! This fuction check if the fucntion works correctly for fiven conditions
//!
//! @param [in] a      a    - coefficient
//! @param [in] b      b    - coefficient
//! @param [in] c      c    - coefficient
//! @param [in] res1   res1 - first root that should be get
//! @param [in] res2   res2 - second root that should be get
//! 
//! @note This function prints "TEST OK" if fucntion "SolveSquare" works 
//!	  correctly on this parameter set, and prints divergences if it doesn't
//!
//}============================================================================

void UnitTestSquare(double a, double b, double c, int nroot,
                    double res1, double res2, int line)
{
        double x1 = 0.0, x2 = 0.0;
        int nres = SolveSquare(a, b, c, &x1, &x2);
        if(nres  == nroot && x1 == res1 && x2 == res2)
        {
                printf("\nTEST OK\n");
        }
        else
        {
                printf("\nTest failed on %d : \n"
                       "nroot = %d, should be %d\n"
                       "x1 = %lg,   should be %lg\n"
                       "x2 = %lg,   should be %lg\n"
                        , line, nres, nroot, x1, res1,  x2, res2);
        }
        return;
}

//-----------------------------------------------------------------------------
//{============================================================================
//! This fuction checks the correctness of function "SolveSquare"
//! for several parameter set and if it works incorrectly, shows on which line
//! test was failed
//!
//}============================================================================


void SquareTest()
{
        UnitTestSquare(0   ,     0 ,     0 , 3 , 0     ,  0     , __LINE__);
        UnitTestSquare(1   ,     1 ,     1 , 0 , 0     ,  0     , __LINE__);
        UnitTestSquare(1   ,     2 ,     1 , 1 , -1    , -1     , __LINE__);
        UnitTestSquare(288 , -1296 ,  1008 , 2 , 3.5   ,  1     , __LINE__);
	UnitTestSquare(1   ,   -53 ,   196 , 2 , 49    ,  4     , __LINE__);
	UnitTestSquare(25  ,   626 ,    25 , 2 , -0.04 ,  -25   , __LINE__);
}

int main()
{
        printf(" # Square equation solver\n"
               " # (c) Daniyal Aliev, 2020 \n\n ");
              
        printf(" # Enter a, b, c: ");

        double a = 0, b = 0, c = 0;
        scanf("%lg %lg %lg", &a, &b, &c);

        double x1 = 0, x2 = 0;
        int Nroots = SolveSquare(a, b, c, &x1, &x2);
        
        assert(Nroots != -1);

        PrintRoots(Nroots, x1, x2);
        
        //SquareTest();
        return 0;
}
