import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/**
 * @brief First step of the assignment : creating a frame with a 
 * scrollable text and three buttons
 */
public class Step1 {
   private JFrame mainFrame;
   private JTextArea testText;
   private JLabel headerLabel;
   private JPanel controlPanel;

   private static final long serialVersionUID = 1L;

   public static void main(String[] args){
      Step1 swingControlDemo = new Step1();  
      swingControlDemo.start();       
   }

   public Step1(){
      mainFrame = new JFrame("java swing GUI INF224 ");
      mainFrame.setSize(400,400);

      mainFrame.setLayout(new GridLayout(3, 1));

      // creating header
      headerLabel = new JLabel("",JLabel.CENTER );
      
      // creating scrollable text
      testText = new JTextArea("", 10, 1);
      JScrollPane scrollPane = new JScrollPane(testText);

      // creating panel to hold buttons
      controlPanel = new JPanel();
      controlPanel.setLayout(new FlowLayout());

      // ensure window closes if break
      mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

      // ending prog if window is closed
      mainFrame.addWindowListener(new WindowAdapter() {
         public void windowClosing(WindowEvent windowEvent){
            System.exit(0);
         }        
      });

      // adding components in order
      mainFrame.add(headerLabel);
      mainFrame.add(scrollPane);
      mainFrame.add(controlPanel);
      mainFrame.setVisible(true); 
   }

   private void start(){
      headerLabel.setText("GUI : Testing step 1"); 

      JButton okButton = new JButton("OK");
      JButton wowButton = new JButton("WOW");
      JButton cancelButton = new JButton("exit");

      okButton.setActionCommand("OK");
      wowButton.setActionCommand("WOW");
      cancelButton.setActionCommand("exit");

      okButton.addActionListener(new ButtonClickListener()); 
      wowButton.addActionListener(new ButtonClickListener()); 
      cancelButton.addActionListener(new ButtonClickListener()); 

      controlPanel.add(okButton);
      controlPanel.add(wowButton);
      controlPanel.add(cancelButton); 

      mainFrame.pack();
      mainFrame.setVisible(true);  
   }


   /**
    * @brief a nested class handling all buttons
    */
   private class ButtonClickListener implements ActionListener{
      public void actionPerformed(ActionEvent e) {
         String command = e.getActionCommand();  
         
         if( command.equals( "OK" ))  {
            testText.append("OK\n");   
         } else if( command.equals( "WOW" ) )  {
            testText.append("WOW\n"); 
         } else {
            // close button 
            System.exit(0);
         }  	
      }		
   }
}