using System;
using System.Collections;
using System.Collections.Generic;

namespace zykTest
{
	public class CSharpCoroutine
	{
		public static void Main()
		{
			Console.WriteLine("Start...");
			var itera = remoteCompile();
			for (; ; )
			{
				var status = itera.MoveNext();
				Console.WriteLine("Check done now...");
				if (status == false)
				{
					break;
				}
			}
			Console.WriteLine("End");
		}
		static IEnumerator remoteCompile()
		{
			Console.WriteLine("In getPara Now...");
			// do something
			yield return null;
			Console.WriteLine("In doCompile Now...");
			// do something
			yield return null;
			Console.WriteLine("In uploadResult Now...");
			// do something
		}
	}
}