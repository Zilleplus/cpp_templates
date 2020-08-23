template<typename DstT, typename SrcT>
DstT implicit_cast (SrcT const& x)
{
    return x;
}

// Using this template will result is an 
// error, only SrcT can be deduced.
// --> DstT becomes a problem here
template<typename SrcT, typename DstT>
DstT implicit_cast_wrong_order (SrcT const& x)
{
    return x;
}

int main()
{
    // double value_error = implicit_cast(-1); // error !
    double value = implicit_cast<double>(-1); // the type of value needs to be specified
    double value2 = implicit_cast_wrong_order<double,int>(-1);
}
