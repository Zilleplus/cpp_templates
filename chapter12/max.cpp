template<typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    ::max<double>(1.0,-3.0);
    ::max(1.0,-3.0); // implicitly deduced to double
    ::max<int>(1.0,-3.0);
}
