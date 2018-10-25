public class Customer{

 private String name;
 private String IC;
 private String address;
 private int phoneNo;
 

 public Customer(String aName,String aIC,String aAddress,int aPhoneNo){
 name = aName;
 IC =aIC;
 address = aAddress;
 phoneNo = aPhoneNo;
 }
 public void setName(String aName){
 name = aName;
 }
 public void setIC(String aIC){
 IC =aIC;
 }
 public void setAddress(String aAddress){
 address = aAddress;
}
public void setPhoneNo( int aPhoneNo){
phoneNo = aPhoneNo;
}
 public String getName(){
 return name;
 }
 public String getIC(){
 return IC;
 }
 public String getAddress(){
 return address;
 }

 public int getPhoneNo(){
return phoneNo;
 }
  public String showDetails( ){
  
         String outputMessage="";
         outputMessage=  " Enter the address of customer :" + address + "\n"
                  + " Enter phone number of customer :" + phoneNo + "\n"
                  + " printing out receipt for "+ name + "...." + " \n" 
                  + " At address :" + address + "\n\n";
		           

         return outputMessage;
 

}
}