public class Movie {

   private String movieTitle; 
   private int cost =0;
   private String category;
   private String catalogueNo;




 public Movie(String aMovieTitle, int aCost,String aCategory,String aCatalogueNo){
  movieTitle = aMovieTitle;
  cost = aCost;
  category = aCategory;
  catalogueNo = aCatalogueNo;
 }//end conductor
 

  public String getMovieTitle(){
  return movieTitle;  
  }
  
  public int getCost(){
  return cost;
  }

  public String getCategory(){
  return category;
  }
 
  public String getCatalogueNo(){
  return catalogueNo;
  }
 
	public String showDetails( ) {
		String output = "";
		output = "DVD title: " + movieTitle + " found"+ "\n"
             + "Details for DVD title " + movieTitle +"\n"
             + "Catalogue No: " + catalogueNo + "\n"
             + " Category: " + category  + "\n"                 
             + " Cost:" + cost +"\n\n"
             +    movieTitle + " is available" +"\n"
             + " Cost to rent is available" +"$"+ cost;
				 
		return output;
		
  
  }
   

}
