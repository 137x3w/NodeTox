{
	'targets': [
    {
    	'target_name': 'ToxAddon',
	  	'conditions': [
	  		['OS=="win"', {
	  			'configurations': {
	              	'Debug': {
	                	'msvs_settings': {
	                  		'VCCLCompilerTool': {
	                    		'RuntimeTypeInfo': 'true',
	                    		# 'AdditionalOptions': ['/GR'],
	                    		'RuntimeLibrary': 2 
	                  		}
	                	}
	              	},
	            	'Release': {                            
	                	'msvs_settings': {
	                  		'VCCLCompilerTool': {
	                    		'RuntimeTypeInfo': 'true',
	                    		# 'AdditionalOptions': ['/GR'],
	                    		'RuntimeLibrary': 2
	                  		}
	                	}
	              	}
            	}
	  		}]
        ],
    	'sources': [ 'toxaddon.cc', 'toxcore.cc' ],
		'include_dirs': [
        	'<!@(node -p \'require("node-addon-api").include\')',
	        #v0.2.0
	        'C:/Users/w3x7311/Desktop/BACKUPWindows/Actual/Programming/NodeJS/toxjs/tox/v0.2.3/buildOnMSVC17/include',
	        'C:/Users/w3x7311/Desktop/BACKUPWindows/Actual/Programming/NodeJS/toxjs/libsodium/include',
	        'C:/Users/w3x7311/Desktop/BACKUPWindows/Actual/Programming/NodeJS/toxjs/pthreads/include',
	        'C:/Users/w3x7311/Desktop/BACKUPWindows/Actual/Programming/NodeJS/toxjs/node_modules/node-addon-api',
      	],
      	'libraries': [
      		'C:/Users/w3x7311/Desktop/BACKUPWindows/Actual/Programming/NodeJS/toxjs/tox/v0.2.3/buildOnMSVC17/fullLinked/vstox.lib'
    	],
      	'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ]
    }]
}