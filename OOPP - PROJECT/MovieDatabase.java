  import java.util.Scanner;
   
	public class MovieDatabase{
	
   
   private Movie[] movies; 
   private Customer[] customer;

	public MovieDatabase(){
         
      movies = new Movie[15];
   	movies[0] = new Movie("The OH in Ohio",10,"Comedy","C0001");
		movies[1] = new Movie("Bring It On",10,"Comedy","C0002");
      movies[2] = new Movie("Shrek",5,"Animation","A0001");   
      movies[3] = new Movie("Joseph: King of Dreams",5,"Animation","A0002");
		movies[4] = new Movie("Barney's Great Adventure",5,"Animation","A0003");
		movies[5] = new Movie("Ice Age 2",5,"Animation","A0004");   
		movies[6] = new Movie("A Bug's Life",8,"Animation","A0005");
		movies[7] = new Movie("We're back",5,"Animation","A0006");
	   movies[8] = new Movie("Flushed away",10,"Animation","A0007");
		movies[9] = new Movie("Over the Hedge", 5,"Animation","A0008");
		movies[10]= new Movie("Operation Undercover",10,"Thriller","T0001");
		movies[11]= new Movie("Inside Man",8,"Thriller","T0002");
		movies[12]= new Movie("Hannibal",5,"Thriller","T0003");
		movies[13]= new Movie("Crank",10,"Thriller","T0004");
		movies[14]= new Movie("The Guardian",10 ,"Thriller","T0005");     
		
      customer= new Customer[6];
      customer[0]=new Customer("Sara","S8927345Y","276 Yishun st 24 S(760276)",93844585);
      customer[1]=new Customer("Diana","S1245689G","123 woodland Rd S(346123)",67345289);
      customer[2]=new Customer("Mark","S8935467B","371 yishun Ring Road S(760371)",90872340);
      customer[3]=new Customer("Don","S8923456E","223 Ang mio kio street 11",64239084);
      customer[4]=new Customer("Johnny","S8976534U"," 354 east coast rd  ",67123456);
      customer[5]=new Customer("Ruth","S8900092L","75 Jurong west Rd",974534302);
      }
      

	public Movie findMovieTitle(String movieTitle)
	{
	Movie movieFound = null;
	
	for(int i = 0; i < movies.length; i ++){
	if (movies[i].getMovieTitle().equalsIgnoreCase(movieTitle)){
	    return movies[i];
		}
		
	                       
	}
	System.out.println("DVD title: " + movieTitle + "  not found" + "\n\n"
                       +  movieTitle + "  is not available" + "\n"
                       + "Serving next customer ... " + "\n\n");
							 

  
  return movieFound;
	}
	public String showMovieDetails(String movieTitle){
	Movie movie;
   movie = findMovieTitle(movieTitle);
	return movie.showDetails();
	}
	
	
	public Customer findName(String name){
   Customer customerFound = null;
      
         for(int i=0;i<customer.length;i++){
            if(customer[i].getName( ).equalsIgnoreCase(name)){
               return customer[i];
            }
		}
         return customerFound;
   }
       public String showCustomerDetails(String name){
         Customer customer;
         customer = findName(name);
         return customer.showDetails();
      }
}
