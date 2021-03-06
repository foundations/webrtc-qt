package com.video.play;

import java.io.File;
import java.util.HashMap;

import android.os.Handler;
import android.os.Message;
import android.util.Log;


public class TunnelCommunication {

	private static TunnelCommunication tunnel = null; //
	
	public static int width = 1280; 
	public static int height = 720;
	
	public static byte frameType; //
	private static byte[] naluData = new byte[width*height*3]; //
	private static int naluDataLen = 4; //
	
	//P2P
	private native int naInitialize(String classPath);
	private native int naTerminate();
	private native int naOpenTunnel(String peerId);
	private native int naCloseTunnel(String peerId);
	private native int naMessageFromPeer(String peerId, String msg);
	private native int naAskMediaData(String peerId);
	
	static 
	{
		System.loadLibrary("gnustl_shared");
		System.loadLibrary("p2p");
	}

	synchronized public static TunnelCommunication getInstance() {
		if (tunnel == null) {
			tunnel = new TunnelCommunication();
		}
		return tunnel;
	}

	/**
	 * 
	 */
	public int tunnelInitialize(String classPath) {
		return naInitialize(classPath);
	}

	/**
	 * 
	 */
	public int tunnelTerminate() {
		return naTerminate();
	}

	/**
	 * 
	 */
	public int openTunnel(String peerId) {
		return naOpenTunnel(peerId);
	}

	private static File myData = null;
	
	/**
	 * 
	 */
	public int closeTunnel(String peerId) {
		return naCloseTunnel(peerId);
	}
	
	public int messageFromPeer(String peerId, String msg) {
		return naMessageFromPeer(peerId, msg);
	}

	/**
	 * 
	 */
	public int askMediaData(String peerId) {
		return naAskMediaData(peerId);
	}
	
	/**
	 * 
	 */
	private static void sendHandlerMsg(Handler handler, int what, HashMap<String, String> obj) {
		Message msg = new Message();
		msg.what = what;
		msg.obj = obj;
		handler.sendMessage(msg);
	}
	

	/**
	 * 
	 */
	public void RecvVideoData(String peerID, byte[] data) {
		int dataLen = data.length;
		frameType = (byte)(data[9]);
		
//		if ((frameType & 0x5F) < 30) {
//			int pushPosition = 10;
//			int frameLen = Tools.getWordValue(data, pushPosition);
//			pushPosition += 2;
//			if (frameLen == (dataLen - pushPosition)) {
//				if ((byte)(frameType & 0x80) != 0) {
//					pushPosition += 4;
//				} else {
//					if(naluDataLen > 4 ){
//						Tools.setIntValue(naluData, 0, naluDataLen-4);
//						if (videoDataCache.push(naluData, naluDataLen) != 0) {
//							videoDataCache.clearBuffer();
//						}
//						naluDataLen = 4;
//					}
//				}
//				int naluLen = dataLen - pushPosition;
//				Tools.CopyByteArray(naluData, naluDataLen, data, pushPosition, naluLen);
//				naluDataLen += naluLen;
//			}
//		}
	}
	
	/**
	 * 
	 */
	public void RecvAudioData(String peerID,byte [] data) {
		
	}
	
	public void TunnelOpened(String peerID){
		Log.i("jni","tunnel opend ");
		
	}
}
