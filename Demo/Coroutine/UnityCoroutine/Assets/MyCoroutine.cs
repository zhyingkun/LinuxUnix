using System.Collections;
using UnityEngine;

public class MyCoroutine : MonoBehaviour
{
	private bool isRunning = false;
	private WaitForFrames myCo = null;

	// Use this for initialization
	void Start()
	{
		StartCoroutine(RunInFrames(3));
		this.isRunning = true;
	}

	// Update is called once per frame
	void Update()
	{
		myCo.IncreaseFrame();
		if (isRunning)
		{
			Debug.Log("MyCoroutine is Running Now");
		}
	}
	// FixedUpdate ==> yield WaitForFixedUpdate ==> Update ==> Other Yield ==> LateUpdate ==> yield WaitForEndOfFrame
	// Now: Start==>Update==>keepWaiting
	private IEnumerator RunInFrames(int num)
	{
		myCo = new WaitForFrames(num);
		yield return myCo;
		this.isRunning = false;
		Debug.Log("End of MyCoroutine");
	}
}

public class WaitForFrames : CustomYieldInstruction
{
	private int frames = 0;
	private int currFrames = 0;
	public WaitForFrames(int num)
	{
		frames = num;
	}
	public void IncreaseFrame()
	{
		currFrames++;
	}
	public override bool keepWaiting
	{
		get
		{
			Debug.Log("Access keepWaiting Now:" + currFrames);
			return currFrames < frames;
		}
	}
}
