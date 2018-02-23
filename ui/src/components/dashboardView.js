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
          tabClickCallback={ this.tabClickCallback }
          contactsTabClickCallback={ this.props.contactsTabClickCallback }
        />
        <DashboardBody 
          renderIndex={ this.state.tabIndex }
          friendsControl={ this.props.dashboardBody.friendsControl }
          groupsControl={ this.props.dashboardBody.groupsControl }
          filesControl={ this.props.dashboardBody.filesControl }
          settings={ this.props.dashboardBody.settings }
        />
    	</div>
    );
  }
}

DashboardView.propTypes = {
  contactsTabClickCallback: PropTypes.func,
};

DashboardView.defaultProps = {
  contactsTabClickCallback: (() => {}),
}

export default DashboardView;
