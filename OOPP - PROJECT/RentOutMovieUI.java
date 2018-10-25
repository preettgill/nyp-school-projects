import java.util.Scanner;

public class RentOutMovieUI{
      
		 public static void main (String args[]){
		
		 String movieTitle,name,proceedRent;
		 Movie movie;
		 Customer customer;
		 String output="";
		 String outputMessage="";
		 MovieDatabase aDatabase=new MovieDatabase();
		 Scanner input = new Scanner (System.in);
	    int x = 1;
		 while ( x <= 100){
	
	do{
       System.out.println("Enter the title of movie:");
       movieTitle =input.nextLine();
		 movie = aDatabase.findMovieTitle(movieTitle);
		 }while(movie == null);
		 
		output = "" + aDatabase.showMovieDetails(movieTitle);
		 System.out.println(output);


		 System.out.println("Proceed to rent? <Y/N>: ");
		 proceedRent = input.nextLine();
		 
			    
		 if(proceedRent.equals("y")||proceedRent.equals("Y")){

		  do{
            System.out.println("Enter the name of Customer:");
				name =input.nextLine();
            customer= aDatabase.findName(name);
         }while(customer==null);
      
            movie.getCost();

				String hire = "Hiring DVD title " + movieTitle + " for $" + movie.getCost() + "\n";
				String next = "Serving next customer......\n\n";
				             

         outputMessage=""+ aDatabase.showCustomerDetails(name)+ hire +"\n" + next;
         System.out.println(outputMessage);
			
					
			}
   	else if (proceedRent.equals("n")||proceedRent.equals("N")){
			System.out.println("Serving next customer ... " + "\n\n"); 
	                     
      }
		x ++;
      }
		
		 System.exit(0);
       }
}