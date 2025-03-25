# RlCraftInvTweakNameGenerator
some tools to fix xml file of InventoryTweak mod in RLCraft

used for bruteForce implementation of generating xml entries

working on:
generating xml entries without tiers
user error handling


program can already generate xml enteries with their own categories (mod name), sub categories (item name) and item tags
everything inside /**/ is completely ignored by program
everything inside of {} is used to generate xml entries

example:
{
mod = ExampleForUsers
items = itemA, itemB, itemC
tiers = Red_Epic, Green_Silly, Blue_Cold
}

will generate:
/* data generated [your system time here]
<ExampleForUsers>
	<itemA>
		<itemARedEpicEFU id="exampleforusers:itema_red_epic"/>
		<itemAGreenSillyEFU id="exampleforusers:itema_green_silly"/>
		<itemABlueColdEFU id="exampleforusers:itema_blue_cold"/>
	</itemA>
	<itemB>
		<itemBRedEpicEFU id="exampleforusers:itemb_red_epic"/>
		<itemBGreenSillyEFU id="exampleforusers:itemb_green_silly"/>
		<itemBBlueColdEFU id="exampleforusers:itemb_blue_cold"/>
	</itemB>
	<itemC>
		<itemCRedEpicEFU id="exampleforusers:itemc_red_epic"/>
		<itemCGreenSillyEFU id="exampleforusers:itemc_green_silly"/>
		<itemCBlueColdEFU id="exampleforusers:itemc_blue_cold"/>
	</itemC>
</ExampleForUsers>
*/
