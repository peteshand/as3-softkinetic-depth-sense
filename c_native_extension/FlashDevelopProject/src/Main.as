package 
{
	import com.rhuno.NativeAdd;
	import flash.display.Sprite;
	
	/**
	 * ...
	 * @author Rhuno
	 */
	public class Main extends Sprite 
	{
	
		public function Main():void 
		{
			var ane:NativeAdd = new NativeAdd();			
			var sum:int = ane.doAdd(5, 5);
			trace(sum);
			ane.dispose();
		}
		
	}
	
}