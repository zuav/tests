class Value {
    String s;

    Value(String ss)
    {
        s = ss;
    }
};

class Private {
    public static void main(String[] args)
    {
        Value val = new Value("abcde");
        System.out.println("private value is: " + val.s);
    }
}
