import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.*;


public class Login extends HttpServlet {

  //Process the HTTP Get request
  public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    
    PrintWriter out = response.getWriter();

    String u_name=request.getParameter("Email");
    String u_pass=request.getParameter("Password");

    
    out.println("<html>");
    out.println("<head><title>Login</title></head>");
    out.println("<body bgcolor=\"#ffffff\">");


    try{
    Class.forName("com.mysql.jdbc.Driver");

    String url = "jdbc:mysql://127.0.0.1/lab_07";

    Connection con=DriverManager.getConnection(url,"root","root");

    Statement st=con.createStatement();
    
     String query="Select * from info where email='"+u_name+"'"+"AND password = '"+u_pass+"'";
   
     ResultSet rs = st.executeQuery( query );
   
     if(rs.next()){

	    out.println("<h1>Record found</h1>");

    	    String email = rs.getString("email");
    	    String passwd = rs.getString("password");

    	    out.println("<h1>User Name: "+email+" </h1>");
	    out.println("<h1>User Address: "+ passwd+ " </h1>");

	  }
     
     else{
    	 out.println("<h1>Error You are not a member</h1>");
          }


out.println("</body></html>");
           st.close();
           con.close();

    }catch(Exception e){

      out.println(e);
    }

  }

}
