import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import ProfileSettingsBody from './settingsView/profileSettingsBody';
import FriendsControlView from './friendsControlView/friendsControlView';
import GroupsControlView from './groupsControlView/groupsControlView';

const styles = theme => ({
  dashboardBody: {
    height: 'calc(100vh - 72px)',
    overflow: 'auto',
  },
});

class DashboardBody extends React.Component {
  constructor(props) {
    super(props);
    this.classes = props.classes;
  }

  render() { 
    return (    
      <Grid item className={ this.classes.dashboardBody }>
        {
          (() => {
            switch(this.props.renderIndex) {
              case 0: return (
                <FriendsControlView
                  requests={ this.props.friendsControl.friendRequests }
                  callbacks={ this.props.friendsControlCallbacks }
                />
              )
              case 1: return (
                <GroupsControlView
                  requests={ this.props.groupsControl.groupRequests }
                  callbacks={ this.props.groupsControlCallbacks }
                />
              )
              case 4: return (
                <ProfileSettingsBody
                  settings={ this.props.settings }
                  callbacks={ this.props.settingsCallbacks }
                />
              )
              default: return (
                <div></div>
              )
            }
          })()
        }
      </Grid>
    );
  }
} 

DashboardBody.propTypes = {
  classes: PropTypes.object.isRequired,
};

export default withStyles(styles)(DashboardBody);
