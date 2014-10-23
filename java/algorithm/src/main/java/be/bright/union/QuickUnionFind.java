package be.bright.union;

import be.bright.tools.StdIn;
import be.bright.tools.StdOut;

/**
 * Created by barroco on 10/21/14.
 */
public class QuickUnionFind {
    private int[] ids;
    private int count;

    public QuickUnionFind(int N){
        ids = new int[N];
        count=N;
        for(int i=0;i<N;++i){
            ids[i]=0;
        }
    }
    
    void union(int p, int q){
        if(connected(p,q))
            return;
        for(int i=0;i<ids.length;++i){
            if(ids[i]==ids[p]){
                ids[i]=ids[q];
            }
        }
        --count;
    }

    int find(int p){
        return ids[p];
    }

    boolean connected(int p, int q){
        return find(p)==find(q);
    }
    int count(){
        return count;
    }

    public static void main(String[]args){
        int len=StdIn.readInt();
        QuickUnionFind union=new QuickUnionFind(len);
        while(!StdIn.isEmpty()){
            int p=StdIn.readInt();
            int q=StdIn.readInt();
            if(!union.connected(p,q)){
                union.union(p,q);
                StdOut.println(p+q);
            }
        }
        StdOut.println(union.count());
    }
}
