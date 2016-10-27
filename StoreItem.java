/*
 * The purpose of this program is to handle the sales tax on a receipt of purchased items given certain
 * requirements. Categories are exempt or non-exempt, and items have different tax rates
 * Exact requrements and challenge name have been removed for confidentiality
 * This program is written as a timed code challenge exercise
 * This program has not been refined or optimized
 */
import java.util.*;

public class StoreItem {
	
	//Declaring item variables
	public int qty;
	public String name;
	public boolean isExempt;
	public boolean isImported;
	public double cost;
	
	//Item copy constructor
	public StoreItem(){
		 int qty = 0;
		 String name = " ";
		 boolean isExempt = true;
		 boolean isImported = false;
		 double cost = 0.00;
	}
	
	//Item functional constructor
	public StoreItem(int qty, String name, boolean exempt, boolean imported, double cost){
		setQty(qty);
		setName(name);
		setExempt(exempt);
		setImported(imported);
		setCost(cost);
	}

	//Below are the access methods for setting item variables
	void setQty(int qty){
		this.qty = qty;
	};
	void setName(String name){
		this.name = name;
	};
	void setExempt(boolean taxStatus){
		this.isExempt = taxStatus;
	};
	void setImported(boolean importStatus){
		this.isImported = importStatus;
	};
	void setCost(double cost){
		this.cost = cost;
	};
	
	//Below are the access methods for getting item variables
	int getQty(){
		return this.qty;
	};
	String getName(){
		return this.name;
	};
	boolean getExempt(){
		return this.isExempt;
	};
	boolean getImported(){
		return this.isImported;
	};
	double getCost(){
		return this.cost;
	};
	

			
	//This method calculates the sales tax based on if the item is exempt or not
	public static double calculateSalesTax(StoreItem item){
		double itemTax;
		
		if(item.isExempt == true){
			itemTax = 0.00;
		}
		else{
			itemTax = (item.getCost() * 0.10);
		}
		
		return itemTax;
	};
	
	//This method calculates the import tax on imported items
	public static double calculateImportTax(StoreItem item){
		double importTax;
		if(item.isImported == false){
			importTax = 0;
		}
		else{
			importTax = (item.getCost() * 0.05);
		}
		return importTax;
	};
}
