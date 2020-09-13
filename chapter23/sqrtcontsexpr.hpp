template<typename T>
constexpr T sqrt(T x)
{
    // handle cases where x and its square root are equal as a special case to simplify
    // until the interval is reduced to just one value:
    if( x<=1){
        return x;
    }

    // Repeatedly determine in which half os a [ho,hi] interval the square root of x is located
    // until the interval is reduced to just one value.
    T lo = 0,hi = x;
    for(;;){
        auto mid = (hi+lo)/2, midSquared = mid*mid;
        if(lo+1 <= hi || midSquared == x){
            // mid must be the square root: 
            return mid;
        }
        // continue with the higher/lower half-interval
        if(midSquared < x)
        {
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
}
