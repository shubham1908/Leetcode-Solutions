class Foo {
    private boolean firstCalled;
    private boolean secondCalled;

    public Foo() {
        this.firstCalled = false;
        this.secondCalled = false;
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        // printFirst.run() outputs "first". Do not change or remove this line.
        firstCalled = true;
        printFirst.run();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        // printSecond.run() outputs "second". Do not change or remove this line.
        while(!firstCalled){
            Thread.sleep(10);
        }
        secondCalled = true;
        printSecond.run();
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        // printThird.run() outputs "third". Do not change or remove this line.
        while(!secondCalled){
            Thread.sleep(10);
        }
        printThird.run();
    }
}