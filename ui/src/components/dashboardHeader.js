import React from 'react';
import PropTypes from 'prop-types';
import { withStyles } from 'material-ui/styles';
import Grid from 'material-ui/Grid';
import AppBar from 'material-ui/AppBar';
import Tabs, { Tab } from 'material-ui/Tabs';
import ContactsIcon from 'material-ui-icons/Contacts';
import PersonIcon from 'material-ui-icons/Person';
import GroupIcon from 'material-ui-icons/Group';
import PermMediaIcon from 'material-ui-icons/PermMedia'
import SettingsIcon from 'material-ui-icons/Settings';
import classnames from 'classnames';

const styles = theme => ({
  tab: {
    margin: 'auto',
  },
  contactsTab: {
    [theme.breakpoints.up('md')]: {
      display: 'none',
    },
  }
});

class DashboardHeader extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      value: 0,
    };
    this.classes = props.classes;
    this.tabChanged = this.tabChanged.bind(this);
  }

  tabChanged(event, value) {
    this.setState({
      value: value
    });
    this.props.tabClickCallback(value);
  }
  
  render() {
    return (
      <div>
        <Grid item>
          <AppBar position="static" color="default" elevation={2}>
            <Tabs
              value={ this.state.value }
              onChange={ this.tabChanged }
              scrollable
              fullWidth
              centered
              scrollButtons="on"
              indicatorColor="primary"
              textColor="primary"
            >
              <Tab label="Friends" icon={<PersonIcon/>} className={ this.classes.tab }/>
              <Tab label="Groups" icon={<GroupIcon/>} className={ this.classes.tab }/>
              <Tab label="Contacts" icon={<ContactsIcon/>} className={ classnames(this.classes.tab, this.classes.contactsTab) }
                onClick={ this.props.contactsClickCallback }
              />
              <Tab label="Files" icon={<PermMediaIcon/>} className={ this.classes.tab }/>
              <Tab label="Settings" icon={<SettingsIcon/>} className={ this.classes.tab }/>
            </Tabs>
          </AppBar>
        </Grid>
      </div>
    );
  }
}

DashboardHeader.propTypes = {
  classes: PropTypes.object.isRequired,
  callbacks: PropTypes.shape({
    tabClickCallback: PropTypes.func,
    contactsClickCallback: PropTypes.func,
  }),
};

DashboardHeader.defaultProps = {
  callbacks: {
    tabClickCallback: function() {},
    contactsClickCallback: function() {},
  }
};

export default withStyles(styles)(DashboardHeader);
