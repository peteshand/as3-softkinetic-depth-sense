package com.rhuno 
{
	import flash.events.EventDispatcher;
	import flash.external.ExtensionContext;
	/**
	 * @author Rhuno
	 */
	public class NativeAdd extends EventDispatcher
	{
		private var _ctx:ExtensionContext;
		
		public function NativeAdd() 
		{
			_ctx = ExtensionContext.createExtensionContext('com.rhuno.NativeAdd', '');
		}
		
		public function doAdd(a:int, b:int):int
		{
			var result:int;
			result = _ctx.call('doAdd', a, b) as int;
			return result;
		}
		
		public function dispose():void
		{
			_ctx.dispose();
		}
		
	}

}