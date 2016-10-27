/*
 * The purpose of this program is to handle the sales tax on a receipt of purchased items given certain
 * requirements. Categories are exempt or non-exempt, and items have different tax rates
 * Exact requrements and challenge name have been removed for confidentiality
 * This program is written as a timed code challenge exercise
 * This program has not been refined or optimized
 */
import java.util.*;
import java.io.*;
import java.lang.*;
import java.math.*;
import java.awt.*;




public class Main {
	
	// Generating hard coded shopping orders. We could parse a file through buffer
			//or we could ask for user input. I am hard coding here to get a minimum viable solution to test

 

	public static void main(String[] args) {
		
		StoreItem r1Item1 = new StoreItem(1, "Book", true, false, 12.49);
		StoreItem r1Item2 = new StoreItem(1, "Music CD", false, false, 14.99);
		StoreItem r1Item3 = new StoreItem(1, "Chocolate bar", true, false, 0.85);
		
		StoreItem r2Item1 = new StoreItem(1, "Imported Box of chocolates", true, true, 10.00);
		StoreItem r2Item2 = new StoreItem(1, "Imported Bottle of Perfume", false, true, 47.50);

		StoreItem r3Item1 = new StoreItem(1, "Imported Bottle of Perfume", false, true, 27.99);
		StoreItem r3Item2 = new StoreItem(1, "Bottle of Perfume", false, false, 18.99);
		StoreItem r3Item3 = new StoreItem(1, "Packet of Headache pills", true, false, 9.75);
		StoreItem r3Item4 = new StoreItem(1, "Imported Box of chocolates", true, true, 11.25);
		
		ArrayList<StoreItem> Receipt1 = new ArrayList<StoreItem>();
		ArrayList<StoreItem> Receipt2 = new ArrayList<StoreItem>();
		ArrayList<StoreItem> Receipt3 = new ArrayList<StoreItem>();
		
		Receipt1.add(r1Item1);
		Receipt1.add(r1Item2);
		Receipt1.add(r1Item3);
		
		Receipt2.add(r2Item1);
		Receipt2.add(r2Item2);
		
		Receipt3.add(r3Item1);
		Receipt3.add(r3Item2);
		Receipt3.add(r3Item3);
		Receipt3.add(r3Item4);
		
		printReceipt(Receipt1);
		printReceipt(Receipt2);
		printReceipt(Receipt3);
		
		
		
	}
		
		 
	//This is the functional method to tally a single receipt
	 public static void printReceipt(ArrayList<StoreItem> receipt){
		 double receiptTaxes = 0.00;
		 double receiptTotal = 0.00;
		 
		 for(int i=0; i < receipt.size(); i++){
			 
			 receiptTaxes += StoreItem.calculateSalesTax (receipt.get(i));
			 receiptTaxes += StoreItem.calculateImportTax(receipt.get(i));
			 receiptTotal += receipt.get(i).getCost();
			 
			 System.out.println(receipt.get(i).getQty() + " " + receipt.get(i).getName() + " : " + receipt.get(i).getCost());
		 }
		 
		 //Attempt to round to the nearest .05 cents
		 receiptTaxes = ((Math.round(receiptTaxes * 20))/ 20 );
		 receiptTotal = ((Math.round(receiptTotal * 20))/ 20 );
		 
		 System.out.println("Sales Taxes: " + receiptTaxes);
		 System.out.println("Total: " + receiptTotal);
							 
	 };
		 

		
		//public double calculateTotal(){
			
			//double receiptTotal;
			
			//receiptTaxes += calculateSalesTax(ArrayList<StoreItem> receipt[i].getItem());
			//return receiptTotal;
		//};
		
		

}