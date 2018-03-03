import React from 'react';
import PropTypes from 'prop-types';
import DashboardHeader from './dashboardHeader';
import DashboardBody from './dashboardBody';

class DashboardView extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      tabIndex: 0,
    };
    this.tabClickCallback = this.tabClickCallback.bind(this);
  }

  tabClickCallback(tabIndex) {
    this.setState((prevState, props) => ({
      tabIndex: tabIndex,
    }));
  }

  render() {
    return (
    	<div>
        <DashboardHeader 
          contactsClickCallback={ this.props.contactsClickCallback }
          tabClickCallback={ this.tabClickCallback }
        />
        <DashboardBody 
          renderIndex={ this.state.tabIndex }
        
          filesControl={ this.props.dashboardBody.filesControl }

          friendsControl={ this.props.dashboardBody.friendsControl }
          friendsControlCallbacks={ this.props.dashboardBody.friendsControlCallbacks }

          groupsControl={ this.props.dashboardBody.groupsControl }
          groupsControlCallbacks={ this.props.dashboardBody.groupsControlCallbacks }

          settings={ this.props.dashboardBody.settings }
          settingsCallbacks={ this.props.dashboardBody.settingsCallbacks }
        />
    	</div>
    );
  }
}

DashboardView.propTypes = {
  contactsTabClickCallback: PropTypes.func,
  dashboardBody: PropTypes.object,
};

DashboardView.defaultProps = {
  contactsTabClickCallback: (() => {}),
  dashboardBody: {},
}

export default DashboardView;
