import java.sql.*;

public class DBConnection {
	private Connection con;

	public void connect() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			con = DriverManager.getConnection(  
				"jdbc:mysql://fdb1030.awardspace.net:3306/4285268_shop",
				"4285268_shop",
				"N1khx234"
			);
			
//			Statement stmt=con.createStatement();  
//			ResultSet rs=stmt.executeQuery("select * from emp");  
//			while(rs.next())  
//				System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));  

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
	}
	
	public void closeConnection() {
		try {
			con.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}
