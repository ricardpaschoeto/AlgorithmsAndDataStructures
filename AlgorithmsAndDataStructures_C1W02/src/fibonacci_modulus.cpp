#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>

extern int64_t lcm_fast(int, int);

void lcm_fast_factors(int a, int b, std::vector<int>& factors)
{
    int64_t lcm = 1;
    int div = 2;
    int atemp = a;
    int btemp = b;

    while (true)
    {
        if (atemp % div == 0 || btemp % div == 0)
        {
            factors.push_back(div);
            lcm *= div;
            if (atemp % div == 0)
                atemp /= div;
            if (btemp % div == 0)
                btemp /= div;
        }
        else if (atemp % div != 0 && btemp % div != 0)
        {
            div++;
        }

        if (atemp == 1 && btemp == 1)
            return;
    }

}

void powers(std::vector<int>& factors, std::vector<int>& factor_powers)
{
    factor_powers.push_back(factors[0]);
    int occurrencies = std::count(factors.begin(), factors.end(), factors[0]);
    factor_powers.push_back(occurrencies);

    if (occurrencies < factors.size())
    {
        for (size_t i = 1; i < factors.size(); i++)
        {
            if (factors[i] != factors[i - 1])
            {
                factor_powers.push_back(factors[i]);
                factor_powers.push_back(std::count(factors.begin(), factors.end(), factors[i]));
            }

        }
    }
}

//int order(int p, int m)
//{
//    std::vector<std::vector<float>> A;
//    std::vector<std::vector<float>> vectorMatrix;
//    std::vector<std::vector<float>> vectorDiag;
//    std::vector<std::vector<float>> vectorMatrixInv;
//
//    for (size_t i = 2; i <= p; i++)
//    {
//        if (p % i == 0)
//        {
//
//            vectorMatrix = { {-0.8507,0.5257},{0.5257,0.8507} };
//            vectorDiag = { {-0.6180,0},{0,1.6180} };
//            vectorMatrixInv = { {-0.8507,0.5257},{0.5257,0.8507} };
//
//            vectorDiag[0][0] = pow(vectorDiag[0][0],i);
//            vectorDiag[1][1] = pow(vectorDiag[1][1],i);
//
//            A = { {0.0,0.0},{0.0,0.0} };
//            // V^-1*D^i*V
//            A[0][0] = vectorMatrix[0][0] * (vectorDiag[0][0] * vectorMatrixInv[0][0] + vectorDiag[1][0] * vectorMatrixInv[0][1]) + vectorMatrix[1][0] * (vectorDiag[0][1] * vectorMatrixInv[0][0] + vectorDiag[1][1] * vectorMatrixInv[0][1]);
//            A[0][1] = vectorMatrix[0][1] * (vectorDiag[0][0] * vectorMatrixInv[0][0] + vectorDiag[1][0] * vectorMatrixInv[0][1]) + vectorMatrix[1][1] * (vectorDiag[0][1] * vectorMatrixInv[0][0] + vectorDiag[1][1] * vectorMatrixInv[0][1]);
//            A[1][0] = vectorMatrix[0][0] * (vectorDiag[0][0] * vectorMatrixInv[1][0] + vectorDiag[1][0] * vectorMatrixInv[1][1]) + vectorMatrix[1][0] * (vectorDiag[0][1] * vectorMatrixInv[1][0] + vectorDiag[1][1] * vectorMatrixInv[1][1]);
//            A[1][1] = vectorMatrix[0][1] * (vectorDiag[0][0] * vectorMatrixInv[1][0] + vectorDiag[1][0] * vectorMatrixInv[1][1]) + vectorMatrix[1][1] * (vectorDiag[0][1] * vectorMatrixInv[1][0] + vectorDiag[1][1] * vectorMatrixInv[1][1]);
//
//            //if (std::fmod((A[0][0]), m) == 1 && std::fmod((A[0][1]), m) == 0 && std::fmod((A[1][0]),m) == 0 && std::fmod((A[1][1]), m) == 1)
//            //{
//                //std::cout << "OK!" << std::endl;
//                std::cout << A[0][0] << " " << A[0][1] << std::endl;
//                std::cout << A[1][0] << " " << A[1][1] << std::endl;
//                //return i;
//            //}
//        }
//    }
//
//    std::cout << std::fmod(A[0][0],m) << " " << std::fmod(A[0][1],m) << std::endl;
//    std::cout << std::fmod(A[1][0],m) << " " << std::fmod(A[1][1],m) << std::endl;
//
//    return 0;
//}

int64_t powersNumbers(std::vector<int>& factor_powers, int m)
{
    if (factor_powers[0] == 2 || factor_powers[0] == 5)
    {
        if (factor_powers[0] == 2)
            return 3 * m / 2;
        else if (factor_powers[0] == 5)
            return (int64_t)4 * m;
    }
    else
    {
        if (factor_powers[1] == 1) {

            int p;
            if ((factor_powers[0] % 10) == 3 || (factor_powers[0] % 10) == 7)
            {
                p = 2 * (factor_powers[0] + 1);
                return p;
            }

            if ((factor_powers[0] % 10) == 1 || (factor_powers[0] % 10) == 9)
            {
                p = factor_powers[0] - 1;
                return p;
            }
        }
        else
        {
            factor_powers[1] -= 1;
            int64_t period = powersNumbers(factor_powers, m);
            return pow(factor_powers[0], factor_powers[1])*period;
        }
    }
}

int64_t pisanoPeriod(int m)
{
    std::vector<int> factors;
    std::vector<int> factor_powers;
    std::vector<int64_t> partialPisanos;
    if (m == 1)
        return m;

    lcm_fast_factors(m, 1, factors);
    powers(factors, factor_powers);

    for (size_t i = 0; i < factor_powers.size() / 2; i++)
    {
        std::vector<int> temp(2);
        temp[0] = factor_powers[2 * i];
        temp[1] = factor_powers[2 * i + 1];
        int64_t pisanos = powersNumbers(temp, pow(temp[0], temp[1]));
        partialPisanos.push_back(pisanos);
    }

    if (partialPisanos.size() > 1) {
        int64_t temp = lcm_fast(partialPisanos[0], partialPisanos[1]);
        for (size_t i = 2; i < partialPisanos.size(); i++)
        {
            temp = lcm_fast(temp, partialPisanos[i]);
        }
        return temp;
    }
            
    return partialPisanos[0];

}

void test_pisano_period()
{
    std::cout << "1 :" << std::endl;
    assert(pisanoPeriod(1) == 1);
    std::cout << "2 :" << std::endl;
    assert(pisanoPeriod(2) == 3);
    std::cout << "3 :" << std::endl;
    assert(pisanoPeriod(3) == 8);
    std::cout << "4 :" << std::endl;
    assert(pisanoPeriod(4) == 6);
    std::cout << "5 :" << std::endl;
    assert(pisanoPeriod(5) == 20);
    std::cout << "6 :" << std::endl;
    assert(pisanoPeriod(6) == 24);
    std::cout << "7 :" << std::endl;
    assert(pisanoPeriod(7) == 16);
    std::cout << "8 :" << std::endl;
    assert(pisanoPeriod(8) == 12);
    std::cout << "9 :" << std::endl;
    assert(pisanoPeriod(9) == 24);
    std::cout << "10 :" << std::endl;
    assert(pisanoPeriod(10) == 60);
    std::cout << "11 :" << std::endl;
    assert(pisanoPeriod(11) == 10);
    std::cout << "12 :" << std::endl;
    assert(pisanoPeriod(12) == 24);
    std::cout << "13 :" << std::endl;
    assert(pisanoPeriod(13) == 28);
    std::cout << "14 :" << std::endl;
    assert(pisanoPeriod(14) == 48);
    std::cout << "15 :" << std::endl;
    assert(pisanoPeriod(15) == 40);
    std::cout << "16 :" << std::endl;
    assert(pisanoPeriod(16) == 24);
    std::cout << "17 :" << std::endl;
    assert(pisanoPeriod(17) == 36);
}

