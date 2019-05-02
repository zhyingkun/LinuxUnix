using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CSharpCoroutine : MonoBehaviour
{
	public GameObject cube;
	private Material mate;
	private Color tmpColor;
	private IEnumerator tmpIterator;
	// Use this for initialization
	void Start()
	{
		mate = cube.GetComponent<MeshRenderer>().sharedMaterial;
		tmpColor = new Color(0.0f, 0.0f, 0.0f, 1.0f);
		tmpIterator = changeColor();
		// StartCoroutine(tmpIterator);
	}

	// Update is called once per frame
	void Update()
	{
		tmpIterator.MoveNext();
	}
	private IEnumerator changeColor()
	{
		for (; ; )
		{
			for (int i = 0; i < 100; i++)
			{
				yield return null;
				tmpColor += new Color(0.01f, 0.01f, 0.01f, 0.0f);
				mate.SetColor("_MainColor", tmpColor);
			}
			for (int i = 0; i < 100; i++)
			{
				yield return null;
				tmpColor -= new Color(0.01f, 0.01f, 0.01f, 0.0f);
				mate.SetColor("_MainColor", tmpColor);
			}
		}
	}
}
