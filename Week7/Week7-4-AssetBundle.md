Download and Free Trees from Asset Store
Go to Meshes and make Fir Tree an asset bundle by selecting "assetBundle" dropdown, and select "new" and name it firtree
Create a folder "Editor" under assets
Create the following script

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;

public class CreateAssetBundle : MonoBehaviour
{
    [MenuItem("Assets/Build Assetbundles")]
    static void BuildAssetBundle()
    {
        string AssetBundleDirectory = "Assets/AssetBundle";
        if(!Directory.Exists(AssetBundleDirectory))
        {
            Directory.CreateDirectory(AssetBundleDirectory);
        }
        else
        {
            BuildPipeline.BuildAssetBundles(AssetBundleDirectory,
                BuildAssetBundleOptions.None, BuildTarget.StandaloneWindows);


        }
    }
}


You should see "Build Assetbundles" under "Assets" menu
Click it and this will make the asset bundles
You should see firtree asset bundle in the asset bundle directory
Do the same for all trees.
Look at the manifestation for each and manifestation for all in AssetBundle.manifest under AssetBundle directory.
Put all of your asset bundles files in Google Drive or firebase (https://firebase.google.com/)

Go to direct link generator site to convert the viewer version to exportable version

https://sites.google.com/site/gdocs2direct/


or you can do it manually:

from:
https://drive.google.com/file/d/1iY4ISL-v6fQ_BUW9BMkU47CoUSoOWB-A/view?usp=share_link
to:
https://drive.google.com/uc?export=download&id=1iY4ISL-v6fQ_BUW9BMkU47CoUSoOWB-A



Create a folder called Scripts and create this script:

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using UnityEngine.Networking.Types;
using static UnityEngine.Rendering.VirtualTexturing.Debugging;


public class LoadAssetBundle : MonoBehaviour
{
    void Start()
    {
        //StartCoroutine(GetAssetBundle());

        //Create a coroutine for each bundle
        //StartCoroutine(GetAssetBundle2());
    }

    public void FirTreeDownload()
    {
        StartCoroutine(GetAssetBundle());
    }

    IEnumerator GetAssetBundle()
    {
        UnityWebRequest www = UnityWebRequestAssetBundle.GetAssetBundle("https://drive.google.com/uc?export=download&id=1I1e8ewZ8I29gzxn5y3yJLFBGi9jn8Dfa\r\n");
        yield return www.SendWebRequest();

        if (www.result != UnityWebRequest.Result.Success)
        {
            Debug.Log(www.error);
        }
        else
        {
            AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(www);
            GameObject obj = (GameObject)bundle.LoadAsset("Fir_Tree");
            Instantiate(obj);
        }
    }

    //IEnumerator GetAssetBundle2()
    //{
    //    UnityWebRequest www = UnityWebRequestAssetBundle.GetAssetBundle("https://drive.google.com/uc?export=download&id=1I1e8ewZ8I29gzxn5y3yJLFBGi9jn8Dfa\r\n");
    //    yield return www.SendWebRequest();

    //    if (www.result != UnityWebRequest.Result.Success)
    //    {
    //        Debug.Log(www.error);
    //    }
    //    else
    //    {
    //        AssetBundle bundle = DownloadHandlerAssetBundle.GetContent(www);
    //        GameObject obj = (GameObject)bundle.LoadAsset("Palm_Tree");
    //        Instantiate(obj);
    //    }
    //}
}


For each asset, you would create a new coroutine
Go to Unity and create a Canvas and UI button and set the"Camera" clear flag to "Solid Color"
Create a GameObject ABLoader and attach the LoadAssetBundle script
Attach the ABLoader, FirTreeDownload function to the button "onClick" in the inspector
