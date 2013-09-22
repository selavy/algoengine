main:
EngineController * Controller = new EngineController( StartDate: date, EndDate: date, Granularity: enum );

Controller->addModule( ScriptLocation: string, PortfolioName: string, StartingAmount: mpf_class )
		       --> ModuleController->addModule() [generate unique module id]--> Module->addPortfolio --> boost::signal 
		       --> FeedbackEngine->recordAction( moduleId, newModule ) --> FeedbackEngine->printToLog( newModule )

Controller->addListOfCompanies( CompanyList: List<string> ) --> ModuleController->addListOfCompanies( CompanyList: List<string> )

Controller->run();

----------------------------------------------------------------------------------------------------------------
Controller::run():
date_iterator currDate( StartDate: date );

while( currDate <= EndDate )
{
	ModuleController->run( currDate );
	++currDate;
}

ModuleController->displayState():
	->for each module:
	      ->boost::signal --> FeedbackEngine->displayStatistics( module )

-----------------------------------------------------------------------------------------------------------------
ModuleController->run( currDate: date ):
for each Module:
    for each Company in CompanyList:
        result = Module->run( currDate, Company ) --> Database::getInstance()->getData( Company, currDate ), Portfolio->getData( Company )

	Portfolio->action( result )  -->  boost::signal --> FeedbackEngine->recordAction( result ) --> FeedbackEngine->printToLog( result )

