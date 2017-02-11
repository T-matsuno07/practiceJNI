class saki{
  public native void hello();

  public static void main(String[] arg){
    System.loadLibrary("Hello");
    saki inst = new saki();
    inst.hello();
  }

}

