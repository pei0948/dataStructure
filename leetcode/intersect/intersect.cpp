class Solution {
public:
    vector<int> intersect1(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int> result;

        if(len1==0 || len2==0)
        {
            return result;
        }

        map<int, int> m;
        for(int i=0; i<len1; i++)
        {
            m[nums1[i]]++;
        }
        for(int i=0; i<len2; i++)
        {
            if(m[nums2[i]]>0)
            {
                result.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return result;
    }

vector<int> intersect2(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int> result;

        if(len1==0 || len2==0)
        {
            return result;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        while((i<len1) && (j<len2))
        {
            if(nums1[i]==nums2[j])
            {
                result.push_back(nums1[i]);
                i++; 
                j++;
            }
            else if(nums1[i]<nums2[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return result;
    }

};